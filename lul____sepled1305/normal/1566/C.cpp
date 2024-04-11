#include<bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        string s,t; cin>>s>>t;
        int type = 0;
        int ans = 0;
        for(int i=0;i<n;i++) {
        	int curType = 0;
        	if(s[i] != t[i])
        		curType = 3;
        	else if(s[i] == '0')
        		curType = 1;
        	else
        		curType = 2;
        	if(type == 0) {
        		if(curType == 1)
        			type = 1;
        		else if(curType == 2)
        			type = 2;
        		else {
        			ans+=2;
        		}
        	}
        	else if(type == 1) {
        		if(curType == 1)
        			ans++,type = 1;
        		else if(curType == 2)
        			ans+=2,type = 0;
        		else {
        			ans+=3;
        			type = 0;
        		}
        	}
        	else {
        		if(curType == 1)
        			ans+=2,type = 0;
        		else if(curType == 2)
        			type = 2;
        		else {
        			ans+=2;
        			type = 0;
        		}
        	}
        }
        if(type == 1)
        	ans++;
        cout<<ans<<endl;
    }
    return 0;
}