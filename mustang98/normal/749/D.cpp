#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200005;

int lastpos[max_n];
int firstpos[max_n];
vector<pair<int, int> > v;

vector<pair<int, int> > last;

vector<int> pos[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, num, st;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        lastpos[i] = -1;
        firstpos[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &num, &st);
        num--;
        pos[num].push_back(i);
        v.push_back(make_pair(num, st));
        lastpos[num] = i;
        if (firstpos[num] == -1)
        {
            firstpos[num] = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (lastpos[i] != -1)
        {
            last.push_back(make_pair(lastpos[i], i));
        }
    }
    sort(last.begin(), last.end());
    /*for (int i = 0; i < last.size(); i++)
    {
        cout << last[i].F + 1 << ' ' << last[i].S + 1 << endl;
    }*/

    int q, k;
    set<int> ebs;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        ebs.clear();
        scanf("%d", &k);
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &num);
            num--;
            ebs.insert(num);
        }
        //cout << k << ' '<< num << endl;
        int lastnotebspos = -1;
        int prelastnotebspos = -1;
        int winner, prewinner;
        int j;
        for (j = last.size() - 1; j >= 0; j--)
        {
            //   ,  
            if (ebs.count(last[j].S)) continue;
            lastnotebspos = last[j].F;
            winner = last[j].S;
            break;
        }
        //cout << lastnotebspos << ' ' <<winner << endl;
        if (lastnotebspos == -1)
        {
            printf("0 0\n");
            continue;
        }

        //     ,   winner
        ebs.insert(winner);
        j--;
        //cout << j << endl;
        //cout << ebs.size();
        for (; j >= 0; j--)
        {
            //   ,  
            if (ebs.count(last[j].S) > 0) continue;
            prelastnotebspos = last[j].F;
            prewinner = last[j].S;
            break;
        }
        //cout << prelastnotebspos << ' ' <<prewinner << endl;
        if (prelastnotebspos == -1) //    winner,    
        {
            printf("%d %d\n", winner + 1, v[firstpos[winner]].S);
            continue;
        }
        int anspos = *(upper_bound(pos[winner].begin(), pos[winner].end(), prelastnotebspos));
        printf("%d %d\n", winner + 1, v[anspos].S);
    }

    return 0;
}