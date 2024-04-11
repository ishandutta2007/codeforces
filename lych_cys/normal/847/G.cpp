#include<bits/stdc++.h>
using namespace std;

int n,a[9]; char s[9];
int main(){
	scanf("%d",&n);
	int i;
	for (i=1; i<=n; i++){
		scanf("%s",s+1);
		for (int j=1; j<=7; j++) if (s[j]-'0') a[j]++;
	}
	for (i=1; i<=7; i++) a[0]=max(a[0],max(a[i],0));
	cout<<a[0]<<endl;
	return 0;
}