#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N,M;
int A[4040];
vector<long long>ret;
void calc(int L,int R)
{
	if(R-L==0)
	{
		ret.clear();
		ret.push_back(0);
		return;
	}
	int mid=L;
	for(int i=L+1;i<R;i++)if(A[mid]>A[i])mid=i;
	vector<long long>l,r;
	calc(L,mid);l.swap(ret);
	calc(mid+1,R);r.swap(ret);
	ret.clear();
	ret.assign(l.size()+r.size(),-(long long)1e18);
	for(int i=0;i<l.size();i++)for(int j=0;j<r.size();j++)
	{
		ret[i+j]=max(ret[i+j],l[i]+r[j]-(long long)A[mid]*i*j*2);
	}
	for(int i=ret.size()-2;i>=0;i--)ret[i+1]=max(ret[i+1],ret[i]+(long long)(M-1-2*i)*A[mid]);
}
main()
{
	cin>>N>>M;
	for(int i=0;i<N;i++)cin>>A[i];
	calc(0,N);
	cout<<ret[M]<<endl;
}