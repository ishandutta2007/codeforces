#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//construct SA by SA-IS O(N)
#include<string>
#include<vector>
struct SA{
	string s;
	vector<int>sa;
	SA(const string&s_):s(s_)
	{
		sa=build(vector<int>(s.begin(),s.end()),256);
	}
	vector<int>induced_sort(const vector<int>&S,const vector<int>&id,const vector<bool>&SL,vector<int>last)
	{
		vector<int>first(last);
		vector<int>ret(id.size());
		ret[0]=id[0];
		for(int i=0;i<id.size();i++)
		{
			if(id[i]>=1&&!SL[id[i]-1])
			{
				ret[first[S[id[i]-1]-1]++]=id[i]-1;
			}
			else if(ret[i]>=1&&!SL[ret[i]-1])
			{
				ret[first[S[ret[i]-1]-1]++]=ret[i]-1;
			}
		}
		for(int i=id.size();i--;)
		{
			if(ret[i]>=1&&SL[ret[i]-1])
			{
				ret[--last[S[ret[i]-1]]]=ret[i]-1;
			}
		}
		return ret;
	}
	vector<int>build(vector<int>S,int maxval)
	{
		if(S.size()<=1)
		{
			return S.empty()?(vector<int>){0}:(vector<int>){1,0};
		}
		S.push_back(0);
		vector<int>cnt(maxval,0);
		vector<bool>SL(S.size());//S=>true,L=>false
		for(int i=S.size();i--;)
		{
			cnt[S[i]]+=1;
			SL[i]=i+1==S.size()||S[i]<S[i+1]||S[i]==S[i+1]&&SL[i+1];
		}
		for(int i=1;i<maxval;i++)cnt[i]+=cnt[i-1];
		vector<int>last(cnt);
		vector<int>id(S.size());
		vector<int>is_LMS(S.size());
		int LMScnt=0;
		for(int i=1;i<S.size();i++)
		{
			if(!SL[i-1]&&SL[i])
			{
				is_LMS[i]=1;
				id[--cnt[S[i]]]=i;
				LMScnt+=1;
			}
		}
		id=induced_sort(S,id,SL,last);
		int LMSsub=1;
		int pre=-1;
		is_LMS[id[0]]=LMSsub++;
		for(int i=1;i<id.size();i++)
		{
			if(is_LMS[id[i]])
			{
				if(pre>=0&&S[pre]==S[id[i]])
				{
					int k;
					for(k=1;S[pre+k]==S[id[i]+k]&&!is_LMS[pre+k]&&!is_LMS[id[i]+k];k++);
					LMSsub-=S[pre+k]==S[id[i]+k]&&is_LMS[pre+k]&&is_LMS[id[i]+k];
				}
				pre=id[i];
				is_LMS[id[i]]=LMSsub++;
			}
		}
		vector<int>newstr(LMScnt);
		vector<int>rev(LMScnt);
		int counter=0;
		for(int i=0;i<S.size();i++)
		{
			if(is_LMS[i])
			{
				newstr[counter]=is_LMS[i];
				rev[counter]=i;
				counter+=1;
			}
		}
		vector<int>sortedLMS=build(newstr,LMSsub);
		id.assign(S.size(),0);
		for(int i=1;i<sortedLMS.size();i++)
		{
			int I=rev[sortedLMS[i]];
			id[cnt[S[I]]++]=I;
		}
		return induced_sort(S,id,SL,last);
	}
	int operator[](int i)const{return sa[i];}
	int lower_bound(const string&t)const
	{
		int L=-1,R=sa.size();
		while(R-L>1)
		{
			int M=L+R>>1;
			if(s.compare(sa[M],t.size(),t)>=0)R=M;
			else L=M;
		}
		return R;
	}
	int upper_bound(const string&t)const
	{
		int L=-1,R=sa.size();
		while(R-L>1)
		{
			int M=L+R>>1;
			if(s.compare(sa[M],t.size(),t)<=0)L=M;
			else R=M;
		}
		return R;
	}
	bool contain(const string&t)const
	{
		int id=lower_bound(t);
		return id<sa.size()&&s.compare(sa[id],t.size(),t)==0;
	}
	int size()const{return sa.size();}
};
//construct LCP O(N) require SA
struct LCP{
	vector<int>lcp;
	LCP(const SA&sa)
	{
		int n=sa.size()-1;
		lcp.assign(n,0);
		vector<int>rank(n+1);
		for(int i=0;i<=n;i++)rank[sa[i]]=i;
		int h=0;
		lcp[0]=0;
		for(int i=0;i<n;i++)
		{
			int j=sa[rank[i]-1];
			h-=h>0;
			for(;i+h<n&&j+h<n&&sa.s[i+h]==sa.s[j+h];h++);
			lcp[rank[i]-1]=h;
		}
	}
	int operator[](int i)const{return lcp[i];}
	int size()const{return lcp.size();}
};
#include<vector>
struct UF{
	int n;
	vector<int>parent,rank;
	vector<long long>cs;
	UF(int n_,vector<long long>cs_):n(n_),parent(n_),rank(n_,1),cs(cs_)
	{
		for(int i=0;i<n_;i++)parent[i]=i;
	}
	int find(int a){return parent[a]!=a?parent[a]=find(parent[a]):a;}
	bool same(int a,int b){return find(a)==find(b);}
	bool unite(int a,int b)
	{
		a=find(a),b=find(b);
		if(a==b)return false;
		if(rank[a]<rank[b])
		{
			parent[a]=b;
			rank[b]+=rank[a];
			cs[b]+=cs[a];
		}
		else
		{
			parent[b]=a;
			rank[a]+=rank[b];
			cs[a]+=cs[b];
		}
		return true;
	}
	long long operator[](int k)const{return cs[k];}
	int size(int a){return rank[find(a)];}
};
int N,C[1<<17],n[1<<17];
int Csa[5<<17];
char T[5<<17];
int len[5<<17];
long long ans=0;
main()
{
	scanf("%d",&N);
	string S;
	for(int i=0;i<N;i++)
	{
		scanf("%s",T);
		n[i]=strlen(T);
		for(int j=0;j<n[i];j++)
		{
			len[S.size()]=n[i]-j;
			S+=T[j];
		}
		if(i+1<N)S+='$';
	}
	for(int i=0;i<N;i++)scanf("%d",&C[i]);
	SA sa(S);
	LCP lcp(sa);
	vector<pair<int,int> >X;X.reserve(lcp.size());
	for(int i=0;i<lcp.size();i++)
	{
		int L=min(lcp[i],min(len[sa[i]],len[sa[i+1]]));
		X.push_back(make_pair(L,i));
	}
	vector<long long>cs(sa.size());
	{
		int slen=0;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<=n[i];j++)Csa[slen+j]=C[i];
			slen+=n[i]+1;
		}
	}
	for(int i=0;i<sa.size();i++)
	{
		int L=i>0?lcp[i-1]:0;
		int R=i<lcp.size()?lcp[i]:0;
		if(len[sa[i]]>L&&len[sa[i]]>R)
		{
			long long now=(long long)len[sa[i]]*Csa[sa[i]];
			if(ans<now)ans=now;
		}
	}
	for(int i=0;i<sa.size();i++)
	{
		cs[i]=Csa[sa[i]];
	}
	sort(X.begin(),X.end());
	reverse(X.begin(),X.end());
	UF uf(sa.size(),cs);
	for(int i=0;i<X.size();)
	{
		if(X[i].first==0)break;
		int j=i;
		while(j<X.size()&&X[i].first==X[j].first)
		{
			uf.unite(X[j].second,X[j].second+1);
			j++;
		}
		while(i<j)
		{
			int id=uf.find(X[i].second);
			long long now=(long long)X[i].first*uf[id];
			i++;
			if(ans<now)ans=now;
		}
	}
	printf("%lld\n",ans);
}