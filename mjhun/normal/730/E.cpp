#include <bits/stdc++.h>
#define snd second
#define pb push_back
#define fst first
#define mp make_pair
#define fore(i,a,n) for(int i = a, qwer = n;i<qwer;i++)

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 100500;

int n;
pair<pair<int,int>,int> x[128];
//fst.snd : -indice

int findpos(){
	for(int i=n-1;i>=0;--i){
		if(x[i].snd>0)return i;
	}
	return -1;
}

int findneg(){
	fore(i,0,n){
		if(x[i].snd<0)return i;
	}
	return -1;
}


int main() {
	scanf("%d",&n);
	fore(i,0,n){
		int a,d;
		scanf("%d%d",&a,&d);
		x[i]=mp(mp(-a,i),d);
	}
	sort(x,x+n);
	int k,r=0;
	while(k=findpos(),k>=0){  // findpos encuentra el mayor indice tal que x[k].snd>0
		x[k].fst.fst-=x[k].snd;
		x[k].snd=0;
		while(k>0&&x[k].fst<x[k-1].fst){
			swap(x[k],x[k-1]);
			k--;
			r++;
		}
	}
	while(k=findneg(),k>=0){  // findneg encuentra el menor indice tal que x[k].snd<0
		x[k].fst.fst-=x[k].snd;
		x[k].snd=0;
		while(k<n-1&&x[k].fst>x[k+1].fst){
			swap(x[k],x[k+1]);
			k++;
			r++;
		}
	}
	printf("%d\n",r);
	return 0;
}