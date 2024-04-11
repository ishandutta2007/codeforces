#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define a first
#define b second
#define pb push_back
llo n,m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,k;
		cin>>n>>k;
		llo co=0;
		llo it[n];
		llo st2=0;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			if(it[i]==k){
				st2=1;
				co+=1;
			}
		}

		if(n==1){
			if(it[0]==k){
				cout<<"yes"<<endl;
			}
			else{
				cout<<"no"<<endl;
			}
			continue;
		}
		if(st2==0){
			cout<<"no"<<endl;
			continue;
		}
		
		llo st=0;
		for(llo i=0;i<n-1;i++){
			if(it[i]>=k and it[i]<=it[i+1]){
				st=1;
			}
		}
		for(llo i=1;i<n;i++){
			if(it[i]>=k and it[i]<=it[i-1]){
				st=1;
			}
		}
		
		for(llo i=0;i<n-2;i++){
			if(it[i]>=k and it[i+1]<k and it[i+2]>=k){
				st=1;
			}
		}

		if(st){
			cout<<"yes"<<endl;
			continue;
		}
		else{
			cout<<"no"<<endl;
			continue;
		}
		continue;
		for(llo i=0;i<n;i++){
			if(it[i]==k){
				llo co=0;
				llo co2=0;
				llo co3=1;
				llo cot=1;
				for(llo j=i+1;j<n;j++){
					cot+=1;
					if(it[j]==k){
						co3+=1;
						if(co<(cot+1)/2 and co+co3>=(cot+1)/2){
							st=1;
						}
						break;
					}
					if(it[j]<k){
						co+=1;
					}
					if(co<(cot+1)/2 and co+co3>=(cot+1)/2){
						st=1;
					}
				}
			}
		}
		for(llo i=0;i<n/2;i++){
			swap(it[i],it[n-i-1]);
		}
		for(llo i=0;i<n;i++){
			if(it[i]==k){
				llo co=0;
				llo co2=0;
				llo co3=1;
				llo cot=1;
				for(llo j=i+1;j<n;j++){
					cot+=1;

					if(it[j]==k){
						co3+=1;
						if(co<(cot+1)/2 and co+co3>=(cot+1)/2){
							st=1;
						}
						break;
					}
					if(it[j]<k){
						co+=1;
					}
					if(co<(cot+1)/2 and co+co3>=(cot+1)/2){
							st=1;
						}
				}
			}
		}
		if(st){
			cout<<"yes"<<endl;
			continue;
		}
		else{
			cout<<"no"<<endl;
			continue;
		}



	}










	return 0;
}