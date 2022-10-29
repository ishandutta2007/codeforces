#include <bits/stdc++.h>
using namespace std;
struct osc{
	string str;
	int id;
}a[1000050];
int n,m;
int pos[1000050];
bool cmp(osc &a,osc &b){
	return a.str<b.str;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i].str;
		for (int j=1;j<m;j+=2) a[i].str[j]=25-(a[i].str[j]-'A')+'A';
		a[i].id=i;
	}
//	for (int i=1;i<=n;i++) cerr << a[i].str << " " << a[i].id << '\n';
	sort(a+1,a+n+1,cmp);
//	for (int i=1;i<=n;i++) cerr << a[i].str << " " << a[i].id << '\n';
	for (int i=1;i<=n;i++) cout << a[i].id << " \n"[i==n];
	return 0;
}