S=raw_input();t='';x='a'
for c in S[::-1]:
    if x<=c:x=c;t+=x
print t[::-1]