#include<bits/stdc++.h>
using namespace std;
int qwq[201];
bool q(int a,int b) {
	cout<<"? "<<a<<' '<<b<<endl;
	char c;
    cin>>c;
	return(c=='>');
}
int main(){
	int t;
    cin>>t;
	while(t--){
		int n;
        cin>>n;
		for(int x=1;x<=n;x++)qwq[x]=q(x*2,x*2-1)?x*2-1:x*2;
		stable_sort(qwq+1,qwq+n+1,q);
		int y=qwq[1]+2*(qwq[1]&1)-1,z=qwq[1];
        for(int x=0;x<=2*n;x++)
        qwq[x]=x;
		swap(qwq[y],qwq[1]);
        swap(qwq[y==2?y:z],qwq[2]);
		stable_sort(qwq+3,qwq+2*n+1,q);
        q(qwq[2],qwq[n+1]);
		cout<<'!'<<endl;
	}
}