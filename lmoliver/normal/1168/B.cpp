#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=300300;
int n;
char s[N];
int main(){
	scanf("%s",s);
	n=strlen(s);
	LL ans=0;
	int l=-1;
	for(int i=0;i<n;i++){
		for(int j=1;i-j-j>l;j++){
			if(s[i]==s[i-j]&&s[i]==s[i-j-j]){
				l=i-j-j;
				break;
			}
		}
		ans+=l+1;
	}
	cout<<ans<<endl;
	return 0;
}