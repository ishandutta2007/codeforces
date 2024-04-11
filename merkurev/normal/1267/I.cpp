/*
Searing until we are swallowed by fire
Trying to reach out for the beaming,
Seductive light once we get
Burned  and here comes the night

We all dreamed of touching the sun
Of being more than we could ever be
Our wings now lie floating on a dead sea

We're following what's hopeless
We're striving for the fire
We're wondering with memories
Caught in the night's desire

We're following the blind men,
Our wings have come undone
And atom follows atom
Unwinding in the sun

No boundariesn when it comes to real passion
No dimensions and no dreams we cannot climb
Creating a universe outside of time

Just keep flying keeping your dead down
Ready for motion, your throat
Stripped bare of moons
Maybe tomorrow your name
Will be carved in stones.

I cannot saw the seam
It faded with my dream
Live a life extreme!

Oblivious to  the downward spiral
And time keeps wandering onward,
It keeps it us at pace
When are we gonna wake up
And find our resting place?
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>

#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 2100031;

void stop_here(){
	cout<<"!"<<endl;
	return;
}

int tests,n;
int C;
int used[N];
int left_son[N],right_son[N];
int winner[N];
int where[N],par[N];

vector<pair<int,int> > edges;
int stress=0;

string make_query(int a,int b){
	if (stress==0)cout<<"? "<<a<<" "<<b<<endl;

	edges.push_back(make_pair(a,b));
	string ret;
	if (stress==0){cin>>ret;
	return ret;}
	else{
	if (a<b)
		return "<";
	return ">";}
}

int who_is_worse(int a,int b){
	if (a==0)
		return b;
	if (b==0)
		return a;
	string compare_result=make_query(a,b);
	if (compare_result=="<")
		return a;
	return b;
}

void build_tree(int v,vector<int> candidates){
	if (candidates.size()==1){
		winner[v]=candidates[0];
		where[candidates[0]]=v;
		return;
	}
	vector<int> left_candidates;
	vector<int> right_candidates;
	for (int i=0;i<candidates.size();i++){
		if (i%2)
			left_candidates.push_back(candidates[i]);
		else
			right_candidates.push_back(candidates[i]);
	}

	++C;
	left_son[v]=C;
	par[C]=v;
	build_tree(C,left_candidates);
	++C;
	par[C]=v;
	right_son[v]=C;
	build_tree(C,right_candidates);
	int here=who_is_worse(winner[left_son[v]],winner[right_son[v]]);
	winner[v]=here;
}

void rebuild(int v){
//	cout<<v<<" "<<winner[v]<<" "<winner[left_son[v]]<<" "<<winner[right_son[v]]<<endl;

/*	if (winner[left_son[v]]==winner[v])
		rebuild(left_son[v]);
	if (winner[right_son[v]]==winner[v])
		rebuild(right_son[v]);*/
	int here=who_is_worse(winner[left_son[v]],winner[right_son[v]]);
	winner[v]=here;
}

int get_minimum(int iter){
	int res=winner[1];
	return res;
}

void run_update(int v){
	//cout<<"@@"<<v<<endl;
	//cout<<par[v]<<endl;
	//cout<<winner[left_son[par[v]]]<<" !!! "<<winner[right_son[par[v]]]<<endl;
	if (v==1) return ;
	rebuild(par[v]);
	run_update(par[v]);
}

int good,bad;

bool have_edge(int a,int b){
	for (int i=0;i<edges.size();i++){
		if (edges[i].first==a&&edges[i].second==b)
			return true;
		if (edges[i].first==b&&edges[i].second==a)
			return true;
	}
	return false;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0);
 //   cin.tie(0);

	srand(13);

//	cin>>n;

if (stress==0)
	cin>>tests;
else
	tests=10000;
//    cin>>n;
    for (;tests;--tests){
    	if (stress==0)
    		cin>>n;
    	edges.clear();
    	for (int i=0;i<=5000;i++){
    		left_son[i]=right_son[i]=winner[i]=0;
    	}

    	vector<int> v;
    	C=1;
    	for (int i=1;i<=n+1;i++){
    		v.push_back(i);
    	}

    	build_tree(1,v);

    	for (int i=n+2;i<=n*2;i++){
    		//cout<<i<<" "<<get_minimum(i)<<endl;
    		int Q=get_minimum(i);
    		int v_id=where[Q];
    		where[i]=v_id;
    		winner[v_id]=i;
    		run_update(v_id);
    	}

    	int ok=0;
    	for (int i=n+1;i<n*2;i++)if (have_edge(i,i+1)==0)ok=1;
    	if (ok==0)
    	{
    		bad++;
    	}
    	else
    	{
    		good++;
    	}
    	stop_here();
    }

//    cout<<good<<" "<<bad<<endl;

    //    cin.get(); cin.get();
    return 0;
}