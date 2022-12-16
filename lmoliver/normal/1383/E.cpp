#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD=1e9+7;
int add(int a,int b){return (a+b)%MOD;}
void dadd(int &a,int b){a=add(a,b);}
int sub(int a,int b){return (a-b+MOD)%MOD;}
void dsub(int &a,int b){a=sub(a,b);}
int mul(int a,int b){return (LL)a*b%MOD;}

const int N=1001001;
int n;
char a[N];
int ans[N]={0};
int tmp[N]={0};

int main(){
	ios::sync_with_stdio(false);
	cin>>a;
	n=strlen(a);
	int tt=0;
	int tz=0;
	for(int i=n-1;i>=0&&a[i]=='0';i--){
		tz++;
	}
	bool az=tz==n;
	int cnt=0;
	for(int i=n-1;i>=0;i--){
		if(a[i]=='0'){
			cnt++;
			ans[i]=ans[i+1];
		}
		else{
			for(int j=0;j<=cnt;j++){
				dsub(tt,tmp[j]);
				tmp[j]=ans[i+j+1];
				dadd(tt,tmp[j]);
			}
			ans[i]=add(tt,add(tz,1));
			cnt=0;
		}
		// cerr<<i<<" "<<ans[i]<<endl;
	}
	int res=0;
	for(int i=0;i<=n;i++){
		if(i&&a[i-1]!='0')break;
		dadd(res,ans[i]);
	}
	if(az)res=n;
	cout<<res<<endl;
	return 0;
}