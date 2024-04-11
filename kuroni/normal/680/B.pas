uses math;

var T: array[1..100] of longint;
    a, n, ans, i: longint;

begin
  read(n,a);
  for i := 1 to n do read(T[i]);
  ans := T[a];
  for i := 1 to min(a-1,n-a) do
      if T[a-i] + T[a+i] = 2 then inc(ans,2);
  for i := min(a-1,n-a)+1 to max(a-1,n-a) do
  begin
      if a-1 < n-a then if T[a+i] = 1 then inc(ans);
      if a-1 >= n-a then if T[a-i] = 1 then inc(ans);
  end;
  write(ans);
end.