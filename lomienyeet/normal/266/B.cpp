#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,T;
    string s;
    cin>>N>>T>>s;
    while(T--){
        for(int i=0;i<N;i++){
		    if(s[i]=='B' &&s[i+1]=='G'){
		        swap(s[i],s[i+1]);
		        i++;
		    }
    	}
	}
	cout<<s<<"\n";
	return 0;
}