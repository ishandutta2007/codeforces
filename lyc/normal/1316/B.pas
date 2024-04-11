var t,i1,i,j,k,ans1,n,l:longint;
    ans,st,st1,st2:ansistring;
    tp:char;
begin
  readln(t);
  for i1:=1 to t do
  begin
    readln(n);
    readln(st);ans:='';ans1:=0;
    i:=0; st1:=st;
    while i<n do
    begin
      inc(i);
      st2:=copy(st1,1,i-1);
      if (i mod 2)xor(length(st) mod 2)=1 then
      begin
        delete(st1,1,i-1);
        st1:=st1+st2;
      end else
      begin
        delete(st1,1,i-1);
        for j:=1 to length(st2) div 2 do
        begin
          tp:=st2[j];
          st2[j]:=st2[length(st2)-j+1];
          st2[length(st2)-j+1]:=tp;
        end;
        st1:=st1+st2;
      end;
      if (ans='')or(st1<ans) then
      begin
        ans:=st1;
        ans1:=i;
      end;
      st1:=st;
    end;
    writeln(ans);
    writeln(ans1);
  end;
end.