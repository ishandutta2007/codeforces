#include<bits/stdc++.h>
using namespace std;
char a[111],b[111];int h[30];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		memset(h,0,sizeof(h));memset(b,0,sizeof(b));memset(a,0,sizeof(a));cin>>a+1;
		int l=strlen(a+1),i,j,nm=0,flg=1;
		for (i=1;i<=l;i++) h[a[i]-'a']++;
		for (i=0;i<26;i++) if (h[i]) nm++;
		if (nm==3)
		{
			int tp[3],t=0;
			for (i=0;i<26;i++) if (h[i]){t++;tp[t-1]=i;}
			if (tp[1]-1==tp[0] && tp[1]+1==tp[2]) {puts("No answer");continue;}
			else if (tp[1]-1==tp[0]) swap(tp[1],tp[2]);
			else swap(tp[0],tp[1]);
			for (i=0;i<3;i++) for (j=1;j<=h[tp[i]];j++) cout<<(char)('a'+tp[i]);
			cout<<endl;
			continue;
		}
		if (nm==4)
		{
			int t=0;for (i=0;i<26;i++) if (h[i]) {t++;if (t==3) {for (j=1;j<=h[i];j++) cout<<(char)('a'+i);break;}};
			t=0;for (i=0;i<26;i++) if (h[i]) {t++;if (t==1) {for (j=1;j<=h[i];j++) cout<<(char)('a'+i);break;}};
			t=0;for (i=0;i<26;i++) if (h[i]) {t++;if (t==4) {for (j=1;j<=h[i];j++) cout<<(char)('a'+i);break;}};
			t=0;for (i=0;i<26;i++) if (h[i]) {t++;if (t==2) {for (j=1;j<=h[i];j++) cout<<(char)('a'+i);break;}};cout<<endl;
			continue;
		}
		int t=0;
		for (i=0;i<26;i++) if (flg && h[i])
		{
			t++;if (t%2==0) continue;for (j=1;j<=h[i];j++)
			if ((int)(b[l]-'a')-1!=i && (int)(b[l]-'a')+1!=i) b[--l]='a'+i;else{puts("No answer");flg=0;break;}
		}
		t=0;
		for (i=0;i<26;i++) if (flg && h[i])
		{
			t++;if (t%2) continue;for (j=1;j<=h[i];j++)
			if ((int)(b[l]-'a')-1!=i && (int)(b[l]-'a')+1!=i) b[--l]='a'+i;else{puts("No answer");flg=0;break;}
		}
		if (flg) cout<<b<<endl;
	}
}