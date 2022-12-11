program project1;

var
   bool : array[1..365] of boolean;
   i,j,n,k,c,ans:longint;
begin
     readln(n,k);
     read(c) ;
     for i:=1 to c do begin
         read(j);
         bool[j]:=true;
     end;
     j:=0;
     ans:=0;
     for i:=1 to n do begin
         if not bool[i] then inc(j);
         if j = k then begin inc(ans); j:=0; end;
         if bool[i] then begin j:=0; inc(ans); end;
     end;
     writeln(ans);
end.