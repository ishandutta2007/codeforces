#include<string>
#include<iostream>
using namespace std;
int n;
string a[555555];
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=n-2; i>=0; i--){
		int l2 = a[i+1].length();
		int l1 = a[i].length();
		int sgn = 0, pos = -1;
		for(int j=0; j<l1 && j<l2; j++)
			if(a[i][j] != a[i+1][j]){
				if(a[i][j] > a[i+1][j]){
					sgn = 1;
					pos = j;
				}
				else
					sgn = -1;
				break;
			}
		if(sgn == -1)continue;
		if(sgn == 0){
			if(l1 <= l2)continue;
			a[i] = a[i].substr(0,l2);
		}else{
			a[i] = a[i].substr(0,pos);
		}
	}
	for(int i=0; i<n; i++)
		cout<<a[i]<<endl;
	return 0;
}