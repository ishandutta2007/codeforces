#include <iostream>
using namespace std;

typedef long long ll;
ll ask(int a, int b) {
ll ans;
cout<<"? " << a << ' ' << b <<endl;
cin>>ans;
return ans;
} 

int main() {
	int t; cin>>t;
while(t--) {
int n; cin>>n;
int x=1,y=n;
while(x<y){
int sr =(x+y) /2+1;
if(ask(1,sr)>0) y=--sr;
else x=sr;
} 
int i=x;
ll delta=ask(i,n)-ask(i+1,n);
int j=i+delta+1;
delta=ask(j,n)-ask(j+1,n);
int k=j+delta;
cout<<"! " <<i<<' ' <<j<<' ' <<k<<endl;
} 
	return 0;
}