module main;

import core.stdc.stdio;

char[101] s;

int main(string[] argv)
{
	int n,want;
	scanf("%d%d",&n,&want);
	scanf("%s",&s);

	int mx=0;
	for(int at=0,to=at;at<n;at=to) {
	    while(to<n&&s[to]!='N') ++to;
	    if(s[at]!='N') continue;
	    while(to<n&&s[to]=='N') ++to;
	    int cur=to-at; if(cur>mx) mx=cur;
	}
	
	bool can=false; int nerr=0;
	for(int i=0;i<want;++i) if(s[i]=='Y') ++nerr;
	for(int i=0;i<=n-want;++i) {
	    if(nerr==0&&(i==0||s[i-1]!='N')&&(i==n-want||s[i+want]!='N')) can=true;
	    if(i==n-want) break;
	    if(s[i]=='Y') --nerr;
	    if(s[i+want]=='Y') ++nerr;
	}

	if(want>=mx&&can) printf("YES\n"); else printf("NO\n");
	return 0;
}