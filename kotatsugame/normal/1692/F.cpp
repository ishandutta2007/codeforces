#include<iostream>
#include<vector>
using namespace std;
int T,N;
int cnt[10];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<10;i++)cnt[i]=0;
		for(int i=0;i<N;i++)
		{
			int a;cin>>a;cnt[a%10]++;
		}
		bool ok=false;
		for(int i=0;i<10;i++)if(cnt[i]>0)
		{
			cnt[i]--;
			for(int j=i;j<10;j++)if(cnt[j]>0)
			{
				cnt[j]--;
				int k=(3-i-j+20)%10;
				if(cnt[k]>0)ok=true;
				cnt[j]++;
			}
			cnt[i]++;
		}
		cout<<(ok?"YES\n":"NO\n");
	}
}