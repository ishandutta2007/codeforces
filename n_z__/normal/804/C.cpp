#include<bits/stdc++.h>
using namespace std;
vector<int>nz_vector_1[300001],nz_vector_2[300001];
int nz_array_1[300001];
map<int,int>nz_map_1;
void nz_DepthFirstSearch_1(int nz_dfs_1,int nz_dfs_2)
{
	nz_map_1.clear();
	for(int nz_for_1=0;nz_for_1<nz_vector_1[nz_dfs_1].size();nz_for_1++)
	if(nz_array_1[nz_vector_1[nz_dfs_1][nz_for_1]])nz_map_1[nz_array_1[nz_vector_1[nz_dfs_1][nz_for_1]]] = 1;
	int nz_DepthFirstSearch_1_auxiliary_1=1;
	for(int nz_for_1=0;nz_for_1<nz_vector_1[nz_dfs_1].size();nz_for_1++)
	if(!nz_array_1[nz_vector_1[nz_dfs_1][nz_for_1]])
	{
		for(;;)if(!nz_map_1[++nz_DepthFirstSearch_1_auxiliary_1])break;
		nz_array_1[nz_vector_1[nz_dfs_1][nz_for_1]]=nz_DepthFirstSearch_1_auxiliary_1;
	}
    for(int nz_for_1=0;nz_for_1<nz_vector_2[nz_dfs_1].size();nz_for_1++)
    if(nz_vector_2[nz_dfs_1][nz_for_1]!=nz_dfs_2)nz_DepthFirstSearch_1(nz_vector_2[nz_dfs_1][nz_for_1],nz_dfs_1);
}
signed main()
{
	ios::sync_with_stdio(false);
	int nz_read_1,nz_read_2;
	cin>>nz_read_1>>nz_read_2;
	int nz_answer_1=0;
	for(int nz_for_1=1;nz_for_1<=nz_read_1;nz_for_1++)
	{
		int nz_auxiliary_1;
		cin>>nz_auxiliary_1;
		nz_answer_1=max(nz_answer_1,nz_auxiliary_1);
		for(int nz_for_2=1;nz_for_2<=nz_auxiliary_1;nz_for_2++)
		{
			int nz_auxiliary_2;
			cin>>nz_auxiliary_2;
			nz_vector_1[nz_for_1].push_back(nz_auxiliary_2);
		}
	}
	if(!nz_answer_1)nz_answer_1=1;
	for(int nz_for_1=1;nz_for_1<nz_read_1;nz_for_1++)
	{
		int nz_auxiliary_1,nz_auxiliary_2;
		cin>>nz_auxiliary_1>>nz_auxiliary_2;
		nz_vector_2[nz_auxiliary_1].push_back(nz_auxiliary_2);
		nz_vector_2[nz_auxiliary_2].push_back(nz_auxiliary_1);
	}
   	nz_DepthFirstSearch_1(1,-1);
   	cout<<nz_answer_1<<endl;
	for(int nz_for_1=1;nz_for_1<=nz_read_2;nz_for_1++)
	cout<<max(1,nz_array_1[nz_for_1]-1)<<' ';
}