dx = [0,1,0,-1]
dy = [-1,0,1,0]

n,m = map(int, raw_input().split())
grid = [raw_input() for __ in range(n)]
dd = map(int, raw_input())

def check(mm):
  sx = 0
  sy = 0
  for i in range(n):
    for j in range(m):
      if grid[i][j] == 'S':
        sx = i
        sy = j

  for x in dd:
    g = mm[x]
    sx += dx[g]
    sy += dy[g]
    if sx < 0 or sx >= n or sy < 0 or sy >= m or grid[sx][sy] == '#':
      return False
    if grid[sx][sy] == 'E':
       return True
  return False

import itertools
print sum(map(check, itertools.permutations(range(4))))