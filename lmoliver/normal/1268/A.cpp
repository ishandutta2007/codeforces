#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1001001;
int n,k;
char ss[N];
int s[N];
bool ok(){
	for(int i=0;i<n;i++){
		if(s[i%k]!=s[i]){
			return s[i%k]>s[i];
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	cin>>ss;
	for(int i=0;i<n;i++){
		s[i]=ss[i]^'0';
	}
	if(!ok()){
		s[k-1]++;
		for(int i=k-1;i>0&&s[i]>=10;i--){
			s[i]-=10;
			s[i-1]++;
		}
	}
	for(int i=k;i<n;i++){
		s[i]=s[i%k]%10;
	}
	cout<<n<<endl;
	for(int i=0;i<n;i++){
		cout<<s[i];
	}
	cout<<endl;
	return 0;
}