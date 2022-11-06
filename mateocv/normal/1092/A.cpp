#include<bits/stdc++.h>
using namespace std;

int main(){
	
	map<int,char> letra;
	letra[1]='a';
	letra[2]='b';
	letra[3]='c';
	letra[4]='d';
	letra[5]='e';
	letra[6]='f';
	letra[7]='g';
	letra[8]='h';
	letra[9]='i';
	letra[10]='j';
	letra[11]='k';
	letra[12]='l';
	letra[13]='m';
	letra[14]='n';
	letra[15]='o';
	letra[16]='p';
	letra[17]='q';
	letra[18]='r';
	letra[19]='s';
	letra[20]='t';
	letra[21]='u';
	letra[22]='v';
	letra[23]='w';
	letra[24]='x';
	letra[25]='y';
	letra[26]='z';
	
	int t; cin>>t;
	
	while(t--){
		
		int n,k,res,rest; cin>>n>>k;
		res=n/k; rest=n/k+n%k;
		if(n%k==0){
			for(int j=1;j<k+1;j++){
				while(res--){
					cout<<letra[j];
				};
				res=n/k;
			}
			
		}else{
			while(rest--){cout<<"a";
			};
			for(int j=2;j<k+1;j++){
				while(res--){
					cout<<letra[j];
				}
			res=n/k;
			}
		}
		
		
		cout<<endl;
	}
	
	
	
	
	
	
	return 0;
}