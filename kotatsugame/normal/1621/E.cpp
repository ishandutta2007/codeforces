#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct dat{
	long long sum;
	int k,id;
};
int T,N,M;
vector<int>A;
vector<dat>B;
vector<pair<int,int> >st;
int ok[1<<17],ok1[1<<17],okd[1<<17];
int oks[1<<17],ok1s[1<<17],okds[1<<17];
int inv[1<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	st.reserve(2e5);
	for(;T--;)
	{
		cin>>N>>M;
		A.resize(N);
		for(int i=0;i<N;i++)cin>>A[i];
		sort(A.begin(),A.end());
		reverse(A.begin(),A.end());
		B.resize(M);
		st.clear();
		for(int i=0;i<M;i++)
		{
			int k;cin>>k;
			B[i].sum=0;
			B[i].k=k;
			B[i].id=i;
			for(int j=0;j<k;j++)
			{
				int b;cin>>b;
				st.push_back(make_pair(i,b));
				B[i].sum+=b;
			}
		}
		sort(B.begin(),B.end(),[](dat&lhs,dat&rhs)
		{
			return lhs.sum*rhs.k>rhs.sum*lhs.k;
		});
		for(int i=0;i<M;i++)
		{
			ok[i]=!((long long)A[i]*B[i].k>=B[i].sum);
			ok1[i]=!(i==0?0:(long long)A[i-1]*B[i].k>=B[i].sum);
			okd[i]=!(i==M-1?0:(long long)A[i+1]*B[i].k>=B[i].sum);
			oks[i+1]=oks[i]+ok[i];
			ok1s[i+1]=ok1s[i]+ok1[i];
			okds[i+1]=okds[i]+okd[i];
			inv[B[i].id]=i;
		}
		for(pair<int,int>p:st)
		{
			int b=p.second;
			int id=inv[p.first];
			int nk=B[id].k-1;
			long long nsum=B[id].sum-b;
			int jd;
			{
				int l=-1,r=M;
				while(r-l>1)
				{
					int mid=(l+r)/2;
					if(B[mid].sum*nk<=nsum*B[mid].k)r=mid;
					else l=mid;
				}
				if(r==id)r++;
				jd=r;
			}
			bool now=true;
			if(id<jd)
			{
				if(oks[id]>0)now=false;
				if(ok1s[jd]-ok1s[id+1]>0)now=false;
				if((long long)A[jd-1]*nk<nsum)now=false;
				if(oks[M]-oks[jd]>0)now=false;
			}
			else
			{
				if(oks[jd]>0)now=false;
				if((long long)A[jd]*nk<nsum)now=false;
				if(okds[id]-okds[jd]>0)now=false;
				if(oks[M]-oks[id+1]>0)now=false;
			}
			cout<<(now?'1':'0');
		}
		cout<<"\n";
	}
}