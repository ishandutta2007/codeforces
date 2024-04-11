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

const int N = 2100031;

int tests;
int n;
int cnt[N];
vector<int> interesting;

int solver(int screen_size){
	int total_screens=0;
	for (int i=0;i<interesting.size();i++){
		int screens_here=interesting[i]/screen_size+(interesting[i]%screen_size>0);
		int overhead=screens_here*screen_size-interesting[i];
		if (overhead>screens_here)
			return -1;
		total_screens+=screens_here;
	}
	return total_screens;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    scanf("%d",&tests);

    for (;tests;--tests){
    	scanf("%d",&n);
    	for (int i=1;i<=n;i++){
    		cnt[i]=0;
    	}
    	for (int i=1;i<=n;i++){
    		int val;
    		scanf("%d",&val);
    		cnt[val]++;
    	}
    	int min_nonzero=1e9;
    	int min_id=-1;

    	interesting.clear();

    	for (int i=1;i<=n;i++){
    		if (cnt[i]<min_nonzero&&cnt[i]>0){
    			min_nonzero=cnt[i];
    			min_id=i;
    		}
    		if (cnt[i]>0)
    			interesting.push_back(cnt[i]);
    	}

    	int ans=1e9;

    	for (int i=1;i<=cnt[min_id]+1;i++){
    		int here=solver(i);
    		if (here==-1)
    			continue;
    		ans=min(ans,here);
    	}

    	printf("%d\n",ans);
    }

//    cin.get(); cin.get();
    return 0;
}