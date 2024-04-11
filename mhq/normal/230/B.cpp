#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <iterator>

using namespace std;

const int N = 1e6;

set<long long> prime;

int lp[N+1];

vector <int> pr;

void erato (){
    for (int i = 2; i<=N; i++) {
        if ( lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
            prime.insert(1ll*i*i);
        }
        for (int j = 0; j < pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; j++) {
            lp[i*pr[j]] = pr[j];
        }
    }
}

int n;

long long x;

int main()
{   erato();
    cin>>n;
    for ( int i = 0; i < n; i++) {
        cin>>x;
        if ( prime.find(x) != prime.end() ) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}