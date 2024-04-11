#include<bits/stdc++.h>
using namespace std;

int n,m,A,B,C,cnt,a[609][609],b[1000009];
string s1,s2;
map<string,int> mp;
void add(int x,int y,int z){
	if (x>y) swap(x,y);
		//cout<<x<<' '<<y<<' '<<z<<endl;
	a[x][y]+=z;
}
int main(){
	scanf("%d%d%d%d%d",&cnt,&A,&B,&m,&C);
	int i,j,x,y,last=0,ans=0;
	for (i=1; i<=cnt; i++){
		cin>>s1>>s2;
		if (!mp[s1]) mp[s1]=++n;
		if (!mp[s2]) mp[s2]=++n;
		x=mp[s1]; y=mp[s2];
		//cout<<x<<' '<<y<<endl;
		if (x==last) add(x,y,B); else add(x,y,A); last=y;
	}
	cnt=0;
	for (i=1; i<=n; i++)
		for (j=i; j<=n; j++) b[++cnt]=a[i][j];
	sort(b+1,b+cnt+1);
	for (i=1; i<=cnt/2; i++) swap(b[i],b[cnt+1-i]);
	for (i=1; i<=cnt && i<=m && b[i]>C; i++) ans+=C;
	for (; i<=cnt; i++) ans+=b[i];
	printf("%d\n",ans);
	return 0;
}