#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define pb push_back
#define a first
#define b second
#define mp make_pair
typedef  long long int llo;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	vector<vector<vector<llo>>> aa;
	vector<vector<llo>> ccc;
	vector<vector<llo>> fff;
	llo aaa;
	llo tot=0;
	for(llo i=0;i<n;i++){
		cin>>aaa;
		vector<llo> bb;
		llo j=0;
		while(j<31){
			bb.pb(aaa%2);
			aaa/=2;
			j++;
		}
		vector<llo> c;
		for(llo j=bb.size()-1;j>=0;j--){
			c.pb(bb[j]);
		}
		fff.pb(c);
	}
	aa.pb(fff);
	llo ind=0;

	while(ind<31){

		vector<vector<vector<llo>>> dd;

		dd.pb(ccc);
		dd.pb(ccc);
		for(llo i=0;i<aa[0].size();i++){
			dd[aa[0][i][ind]].pb(aa[0][i]);
		}

		if(dd[0].size()==0 or dd[1].size()==0){
			ind+=1;
			continue;
		}
		aa.clear();
		aa.pb(dd[0]);
		aa.pb(dd[1]);
		tot+=1<<(30-ind);
		llo ind4=ind;
		for(llo ind2=ind+1;ind2<31;ind2++){
		//	vector<vector<vector<llo>>> dd;
			dd.clear();
			llo st=0;
			llo st2=0;
			vector<llo>  ind3;
			for(llo k=0;k<aa.size();k++){
				dd.pb(ccc);
				dd.pb(ccc);
				llo co=0;
				llo cco=0;
				for(llo i=0;i<aa[k].size();i++){
					//cout<<aa[k][i][ind2]<<" ";
					if(aa[k][i][ind2]==0){
						dd[2*k].pb(aa[k][i]);
						co=1;

					}
					else{
						dd[2*k+1].pb(aa[k][i]);
						cco=1;
					}
				}
				if(co+cco==2){
					st2=1;

				}
				else{
					st=1;
					ind3.pb(k);
				}
			//	cout<<endl;
			}
			//cout<<endl;

			if(st==1 and st2==0){
				continue;
			}
			
			if(st2==1 and st==0){
				tot+=(1<<(30-ind2));
				aa.clear();
				for(llo i=0;i<dd.size();i++){
					aa.pb(dd[i]);
				}
				continue;
			}
			aa.clear();
			for(llo i=0;i<ind3.size();i++){
				if(dd[ind3[i]*2].size()==0){
					aa.pb(dd[ind3[i]*2+1]);
				}
				else{
					aa.pb(dd[ind3[i]*2]);
				}
			}
			if(aa.size()>1){
				continue;
			}
			ind=ind2+1;
			break;

		}
		ind=max(ind,ind4+1);

	}
	cout<<tot<<endl;











	return 0;
}