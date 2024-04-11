/**
    What a boring problem. Knowing that multiset could do that
    is the hardest part of this problem.
**/

#include<bits/stdc++.h>
using namespace std;
const int Sora = 0;
int n,q,i;

set<int> points;
multiset<int> gaps;

int ans  (set<int> &fuck, multiset<int> &kuay){
    if(kuay.empty())
        return 0;
    return (*fuck.rbegin() - *fuck.begin() - *kuay.rbegin());
}

void add(int p, set<int> &fuck, multiset<int> &kuay){
    fuck.insert(p);
    auto key = fuck.find(p);
    int prev=-1,next=-1;
    if(key!=fuck.begin()){
        key--;
        kuay.insert(p - *key);
        prev = *key;
        key++;
    }
    key++;
    if(key!=fuck.end()){
        kuay.insert(*key - p);
        next = *key;
        key--;
    }
    if(prev!=-1 && next!=-1)
        kuay.erase(kuay.find(next-prev));
}

void rem(int p, set<int> &fuck, multiset<int> &kuay){
    auto key = fuck.find(p);
    int prev = -1,next = -1;
    if(key!=fuck.begin()){
        key--;
        kuay.erase(kuay.find(p - *key));
        prev = *key;
        key++;
    }
    key++;
    if(key!=fuck.end()){
        kuay.erase(kuay.find(*key - p));
        next = *key;
        key--;
    }
    if(prev!=-1 && next!=-1)
        kuay.insert(next-prev);
    fuck.erase(p);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q;
    for(i = 0; i < n; i++){
        int a;
        cin>>a;
        add(a,points,gaps);
    }

    cout<<ans(points,gaps)<<endl;

    while(q--){
        int a,f;
        cin>>f>>a;
        if(f==0)
            rem(a,points,gaps);
        else
            add(a,points,gaps);
        cout<<ans(points,gaps)<<"\n";
    }
    return Sora;
}