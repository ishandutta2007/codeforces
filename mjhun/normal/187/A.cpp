#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

int n;
int x[200005];
int y[200005];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",x+i);
	fore(i,0,n)scanf("%d",y+i);
	int r=n;
	int j=0;
	fore(i,0,n){
		while(j<n&&y[j]!=x[i])j++;
		if(j<n)r--;
	}
	printf("%d\n",r);
	return 0;
}