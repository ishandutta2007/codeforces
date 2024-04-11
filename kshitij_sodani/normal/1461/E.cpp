//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo k,l,r,t,x,y;
	cin>>k>>l>>r>>t>>x>>y;
	k-=l;
	r-=l;
	l=0;

	if(y>r){
		if(t<=k/x){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
		return 0;
	}

	if(y>=x){
		if(r>=x+y){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	else{
		if(k+y<=r){
			k+=y;
		}
		if(k<x){
			cout<<"No"<<endl;
			return 0;
		}

		llo xx=(k-x)/(x-y)+1;
		if(t>xx){
			cout<<"No"<<endl;
		}
		else{
			cout<<"Yes"<<endl;

		}
		return 0;
	}


	/*if(x>r){
		cout<<"No"<<endl;
		return 0;
	}*/
/*	if(x>r-y+1){




	}
	else{
		cout<<"Yes"<<endl;
		return 0;
	}*/
	if(true){//r-l<=y+x-2){
		llo st=1;
		llo cur=k;
		llo le=t;
		map<llo,llo> ss;
		if(cur>r-y){
			llo pp=(cur-(r-y))/x;
			cur-=pp*x;
			le-=pp;
			if(cur<0){
				cout<<"No"<<endl;
				return 0;
			}
		}
		while(le>0){
			if(ss.find(cur)!=ss.end()){
				cout<<"Yes"<<endl;
				return 0;
			}
			/*if(cur>=r-y+x){
				cout<<11<<endl;
			}*/
			//assert(cur<r-y+x);

			ss[cur]=1;
			if(cur<=r-y){
				cur+=y;
				cur-=x;
				if(cur<0){
					cout<<"No"<<endl;
					return 0;
				}
				if(cur<(r-y)){
					le-=1;
					continue;
				}
				llo lo=(cur-(r-y))/x;
				cur-=x*lo;
				le-=lo;
				le-=1;
				continue;
			}
			else{
				cur-=x;
				le-=1;
				if(cur<0){
					cout<<"No"<<endl;
					return 0;
				}
			}
		}
		cout<<"Yes"<<endl;
		/*for(llo i=0;i<t;i++){
			if(cur+y<=r){
				cur+=y;
			}
			if(i==1e8){
				break;
			}
			if(cur<x){
				st=0;
				break;
			}
			cur-=x;
		}
		if(st){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}*/


	}

	/*if(x>y){


	}
	else{
		if(r-l<=y+x-2){


		}
		else{
			cout<<"Yes"<<endl;
		}
	}
*/








 
	return 0;
}