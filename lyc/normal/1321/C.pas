uses math;
var n,i,j,k,ans,j1:longint;st:ansistring;l,r:array[0..500,0..500]of char;f:array[0..500,0..500]of longint;
begin
  readln(n);
  readln(st);
  while 1=1 do
  begin
    j:=0;j1:=ord('a')-1;
    for i:=1 to length(st)-1 do
      if abs(ord(st[i])-ord(st[i+1]))=1 then
        if (j=0)or(j<>0)and(max(ord(st[i]),ord(st[i+1]))>j1) then
        begin
          j1:=max(ord(st[i]),ord(st[i+1]));
          if j1=ord(st[i]) then j:=i else j:=i+1;
        end;
    if j=0 then break;
    delete(st,j,1);
    inc(ans);
  end;
  writeln(ans);
end.