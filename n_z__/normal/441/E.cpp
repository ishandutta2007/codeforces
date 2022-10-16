#include<bits/stdc++.h>
using namespace std;
map<int,map<int,double>>f;
int main(){
    int x,k,p;
    cin>>x>>k>>p;
    for(int fx=0;fx<=k;fx++)
	f[0][fx]=log2((x+fx)&(-x-fx));
	for(int fx=0;fx<k;fx++)
	for(int fy=0;fy<=k;fy++)
	f[fx+1][fy-1]+=(1-p/100.0)*f[fx][fy],f[fx+1][fy*2]+=p/100.0*(f[fx][fy]+1);
	printf("%.13f\n",f[k][0]);
}