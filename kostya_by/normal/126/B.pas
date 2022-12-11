program project1;

var
   s,t,st  : ansistring;
   find1, find2 : array[0..2 * 1000000] of boolean;
   res : array[0..2 * 1000000] of longint;
   i,j,k,n,m : longint;
   fl : boolean;
begin
     readln(s);
     t:='';
     for i:=2 to length(s) - 1 do t:=t + s[i];
     st:=s + '$' + t;
     res[0]:=0;
     res[1]:=0;
     k:=0;
     fl:=false;
     for i:=2 to length(st) do begin
         while (k > 0) and (st[i] <> st[k + 1]) do k:=res[k];
         if st[i] = st[k + 1] then inc(k);
         res[i]:=k;
         if fl then find1[k]:=true;
         if st[i] = '$' then fl:=true;
     end;
     k:=res[length(s)];
     while k > 0 do begin
           find2[k]:=true;//st[k] = st[length(s)];
           k:=res[k];
     end;
     for i:=2 * 1000000 downto 1 do begin
         if find1[i] and find2[i] then begin
            for j:=1 to i do write(s[j]);
            halt(0);
         end;
     end;
     writeln('Just a legend');
end.