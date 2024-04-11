#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo q,c;
	
	cin>>q>>c;
	llo co[c];
	memset(co,0,sizeof(co));
	priority_queue<pair<llo,llo>> h;
	for(llo i=0;i<c;i++){
		h.push(mp(-0,-i));
	}
	llo x;
	for(llo i=0;i<q;i++){
		cin>>x;
		x%=c;
		co[x]+=1;
		h.push(mp(-co[x],-x));
		while(true){
			pair<llo,llo> xx;
			xx=h.top();
			xx.a=-xx.a;
			xx.b=-xx.b;
			//cout<<xx.a<<" "<<xx.b<<endl;
			if(co[xx.b]!=xx.a){
				h.pop();
				continue;
			}
			cout<<xx.a*c+xx.b<<endl;
			break;
		}
	}













	return 0;
}