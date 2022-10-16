#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n,l,k;
string str;
char arr[N][N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>l>>k;
	cin>>str;
	sort(str.begin(), str.end());
	int ps = 0;
	int curr = 1;
	
	for(int j=0; j<l; j++){
		for(int i=curr; i<=k; i++){
			arr[i][j] = str[ps++];
		}
		while(arr[k][j] != arr[curr][j])curr++;
	}
	
	for(int j=0; j<l; j++){
		for(int i=1; i<=n; i++){
			if(!arr[i][j]) arr[i][j] = str[ps++];
		}
	}
	
	for(int i=1; i<=n; i++){
		printf("%s\n",arr[i]);
	}
	
	return 0;
}