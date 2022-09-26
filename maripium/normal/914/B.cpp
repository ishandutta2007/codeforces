#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
int cnt[100005];
signed main()
{
int n,a[100005];
memset(cnt,0,sizeof(cnt));
cin>>n;
for(int i=0;i<n;i++){cin>>a[i];cnt[a[i]]++;}
for(int i=0;i<100005;i++){
	if(cnt[i]%2){
		cout<<"Conan";
		return 0;
		}
	}
cout<<"Agasa";
}