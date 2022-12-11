program project1;

var
   s1,s2 : ansistring;
   next : array[1..10000,1..26] of longint;
   used : array[1..26] of longint;
   n,m,i,j,k,ans,pos,poso : longint;
   fl : boolean;
begin
     readln(s1);
     readln(s2);
     n:=length(s1);
     k:=ord(s1[n]) - 96;
     used[k]:=1;
     for i:=1 to 26 do begin
         fl:=false;
         for j:=1 to n do begin
             m:=ord(s1[j]) - 96;
             if m = i then begin
                next[n,i]:=j;
                fl:=true;
                break;
             end;
             if fl then continue;
             next[n,i]:=0;
         end;
     end;
     for i:=n - 1 downto 1 do begin
         for j:=1 to 26 do begin
             if j = k then next[i,j]:=i + 1 else next[i,j]:=next[i + 1,j];
         end;
         k:=ord(s1[i]) - 96;
         used[k]:=1;
     end;
     {for i:=1 to n do begin
         for j:=1 to 26 do begin
             write(next[i,j],' ');
         end;
         writeln;
     end;      }
     n:=length(s2);
     ans:=1;
     pos:=0;
     for i:=1 to n do begin
         inc(pos);
         if pos > length(s1) then begin
            pos:=1;
            inc(ans);
         end;
         k:=ord(s2[i]) - 96;
         if used[k] = 0 then begin
            writeln(-1);
            halt(0);
         end;
         if s1[pos] <> s2[i] then begin
            poso:=pos;
            pos:=next[pos,k];
            if poso > pos then inc(ans);
         end;
     end;
     writeln(ans);
end.