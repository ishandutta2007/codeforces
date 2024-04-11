var t,t1:text;tt,n,i,l,ans:longint;a:ansistring;
begin
  readln(n);
  readln(a);
  for i:=1 to n do
  begin
    if a[i]=')' then inc(l);
    if (l>(i-l))and(a[i]=')') then
      inc(ans);
  end;
  if l<>n/2 then writeln('-1') else writeln(ans*2);
end.