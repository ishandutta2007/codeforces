#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> p(n);
		rep(i,n){
			scanf("%d",&p[i]);
			p[i]--;
		}
		string s;
		cin>>s;
		
		vector<array<int,3>> A;
		array<int,3> temp;
		int c = 0;
		rep(i,n){
			temp[0] = s[i] - '0';
			temp[1] = p[i];
			temp[2] = i;
			A.push_back(temp);
			if(s[i]=='0')c++;
		}
		
		sort(A.begin(),A.end());
		//sort(B.begin(),B.end());
		
		vector<int> ans(n);
		rep(i,n){
			ans[A[i][2]] = i;
		}
		
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%d",ans[i]+1);
		}
		cout<<endl;
	}
	
	return 0;
}