uses math;

var n,d,cnt,ans,i,j: longint;
    str: ansistring;

begin
  readln(n,d);
  for i := 1 to d do
  begin
     readln(str);
     if pos('0',str) <> 0 then inc(cnt) else
       begin
         ans := max(ans,cnt);
         cnt := 0
       end;
  end;
  ans := max(ans,cnt);
  write(ans);
end.