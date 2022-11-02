# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;

int main()
{
	int n, m, ans = 0; char c[100];
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",c); int cnt = 0;
		for(char *p=c;*p;p++)
			if(*p=='4'||*p=='7')cnt++;
		if(cnt<=m)ans++;
	}
	cout << ans << endl;
	return 0;
}