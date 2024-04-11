/*
I whisper and moan
My life seems sealed
Time to face my misery
And my mind flees into
Wounds hat never healed

I coast aside my pretty fears
And I forsake the known
I am on a trip
In search of my black throne

Can I endure the rain?
Can I stand the pain?
Day after day my fate tore me up inside
The rope is cut
Eyes forever shut
I am falling!
Falling!

What I used to feel?
What I used to need?
I don't know who this is from who
I need to be feed

Ghosts keep haunting me
In my shattered soul
And they make it heir abode
Take my self control

Afraid to realize
It's not an unknown farce
I need to be the one to exorcise me

And as a blind man I would dance
Days and years passed by
But there's a whisper
From the soul that hides

Can I endure the rain?
Can I stand the pain?
Day after day my fate tore me up inside
The rope is cut
Eyes forever shut
I am falling!
Falling!

What I used to feel?
What I used to need?
I don't know who this is from who
I need to be feed

Ghosts keep haunting me
In my shattered soul
And they make it heir abode
Take my self control

Spark my screams  there's no deliverance
Darkness falls  there's no deliverance
Haunt my dreams  there's no deliverance
Hell doth rise  there's no deliverance

Can I endure the rain?
Can I stand the pain?
Day after day my fate tore me up inside
The rope is cut
Eyes forever shut
I am falling!
Falling!

What I used to feel?
What I used to need?
I don't know who this is from who
I need to be feed

Ghosts keep haunting me
In my shattered soul
And they make it heir abode
Take my self control

Take my self control
And as a blind man I would dance
Take my self control
My fate tore me up inside
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

int n,m;
int votes_for[200][200];
vector<int> taken;
vector<int> ans;
int DEAD[231];

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n>>m;
    for (int i=1;i<=m;i++){
    	for (int j=1;j<=n;j++){
    		cin>>votes_for[i][j];
    	}
    }

    for (int winner=1;winner<n;winner++){
    	vector<pair<int,int> > order;
    	for (int i=1;i<=m;i++){
    		order.push_back(make_pair(votes_for[i][winner]-votes_for[i][n],i));
    	}
    	sort(order.begin(),order.end());
    	reverse(order.begin(),order.end());
    	int balance=0;
    	taken.clear();
    	for (int i=0;i<order.size();i++){
    		if (balance+order[i].first>=0){
    			taken.push_back(order[i].second);
    			balance+=order[i].first;
    		}
    	}
    	if (taken.size()>ans.size())
    		ans=taken;
    }
    for (int i=0;i<ans.size();i++){
    	DEAD[ans[i]]=1;
    }
    ans.clear();
    for (int i=1;i<=m;i++){
    	if (DEAD[i]==0)
    		ans.push_back(i);
    }

    cout<<ans.size()<<endl;
    for (int i=0;i<ans.size();i++){
    	if (i)
    		cout<<" ";
    	cout<<ans[i];
    }
    cout<<endl;

    //    cin.get(); cin.get();
    return 0;
}