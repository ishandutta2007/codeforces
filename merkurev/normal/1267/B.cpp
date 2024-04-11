/*
Why cause our passion to run and hide
Drown it beneath the rising tide
And cause it shatter upon this earth
Refuse the wonder of this birth?

Sweet sound of yesterday
Wet lot forbidden fires
And the dark snake of sin
Was coiling deep within

Our hearts were lead astray
Climbing walls of desire
Your poison now awaits
It lurks beneath the skin

Why cause our passion to pay the price
To turn our hearts as cold as ice
And hide behind such filthy lies
To toss our hopes towards the sky

Sweet sound of yesterday
Wet lot forbidden fires
And the dark snake of sin
Was coiling deep within

Our hearts were lead astray
Climbing walls of desire
Your poison now awaits
It lurks beneath the skin

On we strive to a new tomorrow!
Close my eyes, dreams are on my side
Glowing beams shattering my sorrow!
Forevermore  surrounded by the light

Sweet sound of yesterday
Wet lot forbidden fires
And the dark snake of sin
Was coiling deep within

Our hearts were lead astray
Climbing walls of desire
Your poison now awaits
It lurks beneath the skin

[2x]
Sweet sound of yesterday
Our hearts were lead astray
Sweet sound of yesterday
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

const int N = 500031;

string st;
vector<pair<char,int> > order;
int cnt;

int solver(){
	if (order.size()%2==0)
		return 0;
	if (order[order.size()/2].second==1)
		return 0;
	for (int i=0;i<order.size();i++){
		int othr=order.size()-i-1;
		if (order[i].first!=order[othr].first)
			return false;
		othr=order[othr].second;
		othr+=order[i].second;
		if (othr<3)
			return false;
	}
	return order[order.size()/2].second+1;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>st;
    for (int i=0;i<st.size();i++){
    	if (i>0&&st[i]!=st[i-1]){
    		order.push_back(make_pair(st[i-1],cnt));
    		cnt=0;
    	}
    	++cnt;
    }
    order.push_back(make_pair(st[st.size()-1],cnt));

    cout<<solver()<<endl;

//    cin.get(); cin.get();
    return 0;
}