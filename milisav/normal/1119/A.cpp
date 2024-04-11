#include<bits/stdc++.h>
using namespace std;
int n;
int c;
int main()
{
	scanf("%d",&n);
	int mc=-1,cc=-1,mc2=-1,cc2=-1;
	int mv=1;
	for(int i=1;i<=n;i++) {
		scanf("%d",&c);
		if(mc==-1) {
			mc=i;
			cc=c;
		}
		else {
			if(cc!=c && mc2==-1) {
				mc2=i;
				cc2=c;
				mv=max(mv,i-mc);
			}
			else {
				if(cc!=c) mv=max(mv,i-mc);
				else {
					if(mc2!=-1) mv=max(mv,i-mc2);
				}
			}
		}
	}
	printf("%d",mv);
	return 0;
}