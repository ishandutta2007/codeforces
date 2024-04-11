#line 1 "a.cpp"
#include<cstdio>
using namespace std;
#line 1 "/home/kotatsugame/library/datastructure/binarytrie.cpp"
#include<array>
#include<vector>
#include<cassert>
template<unsigned int sz,typename T=int>
struct binarytrie{
	using Bit=typename conditional<sz<=32,unsigned int,unsigned long long>::type;
	struct node{
		T cnt;
		array<int,2>nxt;
		node():cnt(0),nxt({-1,-1}){}
	};
	vector<node>v;
	binarytrie(){v.emplace_back();}
	void insert(Bit x){add(x,1);}
	void erase(Bit x){add(x,-1);}
	void add(Bit x,T k)
	{
		assert(0<=x&&(x>>sz)==0);
		int p=0;
		v[p].cnt+=k;
		for(int i=sz;i--;)
		{
			int j=x>>i&1;
			if(v[p].nxt[j]==-1)
			{
				v[p].nxt[j]=v.size();
				v.emplace_back();
			}
			p=v[p].nxt[j];
			v[p].cnt+=k;
		}
	}
	T count(Bit x,Bit xor_val=0)const//[0,x)
	{
		assert(0<=xor_val&&(xor_val>>sz)==0);
		if(x<0)return 0;
		else if(x>>sz)return v[0].cnt;
		T ret=0;
		int p=0;
		for(int i=sz;i--;)
		{
			int j=x>>i&1,k=xor_val>>i&1;
			if(j==0)p=v[p].nxt[k];
			else
			{
				if(v[p].nxt[k]>=0)ret+=v[v[p].nxt[k]].cnt;
				p=v[p].nxt[!k];
			}
			if(p==-1)break;
		}
		return ret;
	}
	Bit max(Bit xor_val=0)const
	{
		assert(0<=xor_val&&(xor_val>>sz)==0);
		int p=0;
		Bit ret=0;
		for(int i=sz;i--;)
		{
			ret<<=1;
			int k=xor_val>>i&1;
			if(v[p].nxt[!k]>=0&&v[v[p].nxt[!k]].cnt>0)
			{
				p=v[p].nxt[!k];
				ret|=1;
			}
			else p=v[p].nxt[k];
		}
		return ret;
	}
	Bit min(Bit xor_val=0)const
	{
		assert(0<=xor_val&&(xor_val>>sz)==0);
		int p=0;
		Bit ret=0;
		for(int i=sz;i--;)
		{
			ret<<=1;
			int k=xor_val>>i&1;
			if(v[p].nxt[k]>=0&&v[v[p].nxt[k]].cnt>0)p=v[p].nxt[k];
			else
			{
				p=v[p].nxt[!k];
				ret|=1;
			}
		}
		return ret;
	}
	Bit find_by_order(T ord,Bit xor_val=0)const
	{
		assert(0<=xor_val&&(xor_val>>sz)==0);
		assert(0<=ord&&ord<v[0].cnt);
		int p=0;
		Bit ret=0;
		for(int i=sz;i--;)
		{
			ret<<=1;
			int k=xor_val>>i&1;
			if(v[p].nxt[k]>=0)
			{
				if(ord>=v[v[p].nxt[k]].cnt)
				{
					ord-=v[v[p].nxt[k]].cnt;
					p=v[p].nxt[!k];
					ret|=1;
				}
				else p=v[p].nxt[k];
			}
			else
			{
				p=v[p].nxt[!k];
				ret|=1;
			}
		}
		return ret;
	}
	T order_of_key(Bit x,Bit xor_val=0)const{return count(x,xor_val);}
};
#line 4 "a.cpp"
int N,K;
main()
{
	scanf("%d%d",&N,&K);
	binarytrie<30>P;
	long long ans=0;
	int now=0;
	P.insert(now);
	for(int i=0;i<N;i++)
	{
		int A;
		scanf("%d",&A);
		now^=A;
		ans+=i+1-P.count(K,now);
		P.insert(now);
	}
	printf("%lld\n",ans);
}