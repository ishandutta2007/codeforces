#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void solve(){
	string a,b;
	cin>>a>>b;
	int n=a.length();
	int pos=0;
	for(int i=0;i<n;i++){
		if(a[i]=='+') pos++;
		else pos--;
	}
	int pos2=0,cnt=0;
	for(int i=0;i<n;i++){
		if(b[i]=='+') pos2++;
		else if(b[i]=='-') pos2--;
		else cnt++;
	}
	if(cnt==0){
		if(pos2==pos){
			cout<<"1.000000000\n";
		}
		else{
			cout<<"0.000000000\n";
		}
		return;
	}
	int diff=abs(pos-pos2);
	double totcnt=0,temp;
	for(int i=0;i<pow(2,cnt);i++){
		temp=0;
		for(int j=0;j<cnt;j++){
			if((i&(1<<j))==0){
				temp++;
			}
			else{
				temp--;
			}
		}
		if(temp==diff) totcnt++;
	}
	cout << fixed << setprecision(9) << totcnt/pow(2,cnt) << endl;
}

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    solve();
//    multitest
}