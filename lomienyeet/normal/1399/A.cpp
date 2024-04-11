#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define yy "YES\n"
#define nn "NO\n"
void solve(){
	int N;
	cin>>N;
	int a[N];
	bool flag=true,chk=true;
	for(int i=0;i<N;i++){
		cin>>a[i];
		if(i>=1 and a[i]!=a[i-1])chk=false;
	}
	if(chk){
		cout<<yy;
		return;
	}
	if(N==1){
		cout<<yy;
		return;
	}
	sort(a,a+N);
	for(int i=1;i<N;i++){
		if(a[i]>(a[i-1]+1)){
			flag=false;
		}
	}
	if(flag==true)cout<<yy;
	else cout<<nn;
	return;
}
int main(){
    int T=1;
	cin>>T;
    while(T--){
        solve();
    }
    return 0;
}