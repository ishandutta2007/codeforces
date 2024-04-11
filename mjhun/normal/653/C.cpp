#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

int x[200005];
int n,q,r;

int doit(int i, int j){
	assert(i!=j);
	if(i>j)swap(i,j);
	if(i+1==j){
		int s=0;
		if(i%2==0){
			if(x[i]<=x[j])return 0;
			s--;
			if(i&&x[j]>=x[i-1])return 0;
			if(j<n-1&&x[i]<=x[j+1])return 0;
			if(i&&x[i]>=x[i-1])s--;
			if(j<n-1&&x[j]<=x[j+1])s--;
		}
		else {
			if(x[i]>=x[j])return 0;
			s--;
			if(i&&x[j]<=x[i-1])return 0;
			if(j<n-1&&x[i]>=x[j+1])return 0;
			if(i&&x[i]<=x[i-1])s--;
			if(j<n-1&&x[j]>=x[j+1])s--;
		}
		return q+s==0;
	}
	int s=0;
	if(i%2==0){
		if(i&&x[j]>=x[i-1]||i<n-1&&x[j]>=x[i+1])return 0;
		if(i&&x[i]>=x[i-1])s--;
		if(i<n-1&&x[i]>=x[i+1])s--;
	}
	else {
		if(i&&x[j]<=x[i-1]||i<n-1&&x[j]<=x[i+1])return 0;
		if(i&&x[i]<=x[i-1])s--;
		if(i<n-1&&x[i]<=x[i+1])s--;
	}
	if(j%2==0){
		if(j&&x[i]>=x[j-1]||j<n-1&&x[i]>=x[j+1])return 0;
		if(j&&x[j]>=x[j-1])s--;
		if(j<n-1&&x[j]>=x[j+1])s--;
	}
	else {
		if(j&&x[i]<=x[j-1]||j<n-1&&x[i]<=x[j+1])return 0;
		if(j&&x[j]<=x[j-1])s--;
		if(j<n-1&&x[j]<=x[j+1])s--;
	}
	return q+s==0;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",x+i);
	fore(i,0,n-1)if(i%2==0&&x[i]>=x[i+1]||i%2==1&&x[i]<=x[i+1])q++;
	int j=-1;
	fore(i,0,n-1){
		if(i%2==0&&x[i]>=x[i+1]||i%2==1&&x[i]<=x[i+1]){j=i;break;}
	}
	assert(j>=0);
	// tengo que cambiar j o j+1 por algo
	r=doit(j,j+1);
	fore(i,0,n){
		if(i!=j&&i!=j+1)r+=doit(j,i),r+=doit(j+1,i);
	}
	printf("%d\n",r);
	return 0;
}