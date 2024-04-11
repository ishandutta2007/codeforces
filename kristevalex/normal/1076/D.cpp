#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

struct edge { int to; long long length; int ind;  };     \

vector< vector<edge> > graph;


vector<pair<int, int>> edges;

long long a, b, k, n, m, tmp1, tmp2, tmp, ans = 0;



int dijkstra(int source) {
    int time = 0;

    vector<long long> min_distance( graph.size(), LLONG_MAX );
    min_distance[ source ] = 0;

    vector<pair<int, int>> min_distance_ind( graph.size(), {INT_MAX, -10});

    set< pair<int,int> > active_vertices;
    active_vertices.insert( {0,source} );

    while (!active_vertices.empty()) {
        int where = active_vertices.begin()->second;
        //if (where == target) return min_distance[where];
        active_vertices.erase( active_vertices.begin() );
        for (auto ed : graph[where])
            if (min_distance[ed.to] > min_distance[where] + ed.length) {

                ++time;
                active_vertices.erase( { min_distance[ed.to], ed.to } );

                min_distance[ed.to] = min_distance[where] + ed.length;
                min_distance_ind[ed.to].second = ed.ind;
                //cout << ed.to << " " << min_distance[ed.to] << " ghjk " << min_distance_ind[ed.to].second << endl;
                min_distance_ind[ed.to].first = time;

                active_vertices.insert( { min_distance[ed.to], ed.to } );
            }
    }

    sort(min_distance_ind.begin(), min_distance_ind.end());


    vector<int> ansers;
    vector<bool> is_edge( m, false );
    for (int i = 0; i < n; ++i)
        {
        //cout << min_distance_ind[i].first << endl;
        if (min_distance_ind[i].second >= 0)
                {
                is_edge[min_distance_ind[i].second] = true;
                ansers.push_back(min_distance_ind[i].second);
                }
        }

    if (k > ansers.size()) k = ansers.size();

    cout << k << endl;

    for (int i = 0; i < k; i++)
        {
        cout << ansers[i]+1 << " ";
        }



}


vector<long long> data;







int main()
    {
    //FAST;


    cin >> n >> m >> k;

    graph.resize(n);

    for (int i = 0; i < m; i++)
        {
        cin >> tmp1 >> tmp2 >> tmp;
        --tmp1;
        --tmp2;
        graph[tmp1].push_back({tmp2, tmp, i});
        graph[tmp2].push_back({tmp1, tmp, i});
        edges.push_back({tmp1, tmp2});
        }


    dijkstra(0);


    return 0;
    }