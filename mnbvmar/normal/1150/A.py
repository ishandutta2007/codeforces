R = int(input().split()[-1])

best_buy = min(map(int, input().split()))
best_sell = max(map(int, input().split()))

num_buy = R // best_buy

print(max(R, R + (best_sell - best_buy) * num_buy))