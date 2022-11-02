[n, m, k] = map(int, raw_input().strip().split(' '))
print (k-1)/2/m+1, (k-1)/2%m+1, "RL"[k%2]