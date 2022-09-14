#include<iostream>
using namespace std;
//Disjoint Sparse Table
#include<vector>
template<typename T>
struct DST{
	int n;
	vector<vector<T> >dat;
	DST(const vector<T>&v={})
	{
		n=v.size();
		dat.push_back(v);
		for(int i=2;i<n;i<<=1)
		{
			dat.push_back(vector<T>(n));
			for(int j=i;j<n;j+=i<<1)
			{
				dat.back()[j-1]=dat[0][j-1];
				for(int k=2;k<=i;k++)
				{
					dat.back()[j-k]=max(dat[0][j-k],dat.back()[j-k+1]);
				}
				dat.back()[j]=dat[0][j];
				for(int k=2;k<=i&&j+k<=n;k++)
				{
					dat.back()[j+k-1]=max(dat.back()[j+k-2],dat[0][j+k-1]);
				}
			}
		}
	}
	T query(int l,int r)const//[l,r)
	{
		if(l<0)l=0;
		if(r>n)r=n;
		r--;
		if(l==r)return dat[0][l];
		int k=31-__builtin_clz(l^r);
		return max(dat[k][l],dat[k][r]);
	}
};
int N,M;
int A[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>M;
	for(int i=0;i<M;i++)cin>>A[i];
	DST<int>dst(vector<int>(A,A+M));
	int Q;cin>>Q;
	for(;Q--;)
	{
		int sx,sy,gx,gy,K;
		cin>>sy>>sx>>gy>>gx>>K;
		sx--,gx--;
		if((sy-gy)%K!=0)
		{
			cout<<"NO\n";
			continue;
		}
		if(sx==gx)
		{
			cout<<"YES\n";
			continue;
		}
		if(sx>gx)swap(sx,gx);
		int UP=N-(N-sy)%K;
		if((gx-sx)%K==0&&dst.query(sx,gx+1)<UP)cout<<"YES\n";
		else cout<<"NO\n";
	}
}