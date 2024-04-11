#include <bits/stdc++.h>
using namespace std;

const int N =1e5+9;  
const int Q =1e7+9;
long long n,m,p,q,inv[Q];  
char s[N];
int main()
{
	int t,j;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		p=0;
		q=0;
		for(j=0;j<=(n-1)/2;j++) {
			cin>>s[j];
			if(s[j]=='0') {
				p++;
            } 
		}
		for(;j<n;j++) {
			cin>>s[j];
			if(s[j]=='0') {
				p++;
			} 
			if(s[j]-s[n-1-j]) {
				q++;
			}
		}
		if(p==0) {
			cout<<"DRAW"<<endl;
			continue;
		}
		if(p-q==0) {
			cout<<"ALICE"<<endl;
			continue;
		}
		if (q==0) {
			if (n%2==1&&s[n/2]=='0'&&p!=1) {
			    cout<<"ALICE"<<endl;
		    }
		    else {
			    cout<<"BOB"<<endl;
	    	}
	    	continue;
		}
		if (n%2==1&&s[n/2]=='0'&&p==2&&q==1) {
            cout<<"DRAW"<<endl;
        }
        else {
            cout<<"ALICE"<<endl;
        }
	}
	return 0;
}