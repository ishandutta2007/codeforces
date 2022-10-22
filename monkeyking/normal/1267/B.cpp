#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <deque>
#include <bits/stdc++.h>
//#include "testlib.h"
using namespace std;
#define ll long long
#define pii pair<int,int>
#define qi ios::sync_with_stdio(0)

bool debug=true;

/*    *************************************
	  * Written in New Computer           *
	  * The following code belongs to     *
	  * XiaoGeNintendo of HellHoleStudios *
	  *************************************
*/
template<typename T1,typename T2>ostream& operator<<(ostream& os,pair<T1,T2> ptt){
	os<<ptt.first<<","<<ptt.second;
	return os;
}
template<typename T>ostream& operator<<(ostream& os,vector<T> vt){
	os<<"{";
	for(int i=0;i<vt.size();i++){
		os<<vt[i]<<" ";
	}
	os<<"}";
	return os;
}


string s;
string sh;
vector<int> v;
int main(int argc,char* argv[]){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(i==0 || s[i]!=s[i-1]){
			v.push_back(1);
			sh+=s[i];
		}else{
			v.back()++;
		}
	}
	
//	cout<<sh<<" "<<v<<endl;
//	

	string ssh=sh;
	reverse(ssh.begin(),ssh.end());
	if(ssh!=sh){
		cout<<"0";
		return 0;
	}
	if(ssh.size()%2==0){
		cout<<"0";
		return 0;
	}
	
	int mid=v.size()/2;
	int l=mid-1,r=mid+1;
	if(v[mid]<2){
		cout<<"0";
		return 0;
	}
	while(l>=0 && r<v.size()){
		if(v[l]+v[r]<3){
			cout<<"0";
			return 0;
		}
		l--;r++;
	}
	
	cout<<v[mid]+1<<endl;
	return 0;
}