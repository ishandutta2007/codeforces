#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int x[200005];
int sp[200005];
int n;

int main(){
	scanf("%d",&n);
	while(n--){
		int a;
		scanf("%d",&a);x[a]++;
	}
	fore(i,1,200005)sp[i]=sp[i-1]+x[i-1];
	ll r=-1;
	fore(i,1,200001){
		if(x[i]){
			ll r0=0;
			for(int j=i;j<200001;j+=i){
				r0+=1LL*j*(sp[min(j+i,200003)]-sp[j]);
			}
			r=max(r,r0);
		}
	}
	cout<<r<<endl;
	return 0;
}