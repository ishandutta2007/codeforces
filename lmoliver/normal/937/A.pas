var n,i,j,t,ans:longint;a:array[0..100]of longint;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do for j:=i+1 to n do if a[i]>a[j]then
  begin
    t:=a[i];
    a[i]:=a[j];
    a[j]:=t;
  end;
  for i:=1 to n do if a[i]<>a[i-1]then inc(ans);
  writeln(ans);
end.