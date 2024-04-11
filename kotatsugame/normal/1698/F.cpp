#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,A[500],B[500];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		for(int i=0;i<N;i++)cin>>B[i];
		bool ok=A[0]==B[0];
		vector<pair<int,int> >ans;
		for(int i=1;ok&&i<N;i++)
		{
			if(A[i]==B[i])continue;
			int j=i;
			while(j<N)
			{
				if(A[j]==B[i])
				{
					if(A[j-1]==A[i-1]||j+1<N&&A[j+1]==A[i-1])break;
				}
				j++;
			}
			if(j==N)
			{
				ok=false;
				break;
			}
			if(j+1<N&&A[j+1]==A[i-1])
			{
				reverse(A+i-1,A+j+2);
				ans.emplace_back(i-1,j+1);
				//for(int j=0;j<N;j++)cout<<A[j]<<" ";cout<<endl;
				continue;
			}
			bool done=false;
			for(int l=j-1;!done&&l>=i-1;l--)
			{
				for(int r=j;r<N;r++)if(A[l]==A[r])
				{
					reverse(A+l,A+r+1);
					ans.emplace_back(l,r);
					//for(int j=0;j<N;j++)cout<<A[j]<<" ";cout<<endl;
					done=true;
					break;
				}
			}
			if(!done)
			{
				ok=false;
				break;
			}
			j=i;
			while(j<N)
			{
				if(A[j]==B[i])
				{
					if(j+1<N&&A[j+1]==A[i-1])break;
				}
				j++;
			}
			reverse(A+i-1,A+j+2);
			ans.emplace_back(i-1,j+1);
			//for(int j=0;j<N;j++)cout<<A[j]<<" ";cout<<endl;
		}
		if(ok)
		{
			cout<<"YES\n"<<ans.size()<<"\n";
			for(pair<int,int>p:ans)cout<<p.first+1<<" "<<p.second+1<<"\n";
		}
		else cout<<"NO\n";
	}
}