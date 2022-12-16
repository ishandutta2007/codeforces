#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=500500;
char s[N];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	LL ans=0;
	for(char i='a';i<='z';i++){
		for(char j='a';j<='z';j++){
			LL tans=0;
			LL t1=0;
			for(int k=0;k<n;k++){
				if(s[k]==j){
					tans+=t1;
				}
				if(s[k]==i){
					t1++;
				}
			}
			tans=max(tans,t1);
			ans=max(ans,tans);
		}
	}
	cout<<ans<<endl;
	return 0;
}